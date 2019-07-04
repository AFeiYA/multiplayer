// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"





bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::ToCreateGameMenu);

	if (!ensure(FindButton != nullptr)) return false;
	FindButton->OnClicked.AddDynamic(this, &UMainMenu::ToJoinGameMenu);

	if (!ensure(CreateButton != nullptr)) return false;
	CreateButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UMainMenu::ToLobbyMenu);

	if (!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	if (!ensure(LeaveButton != nullptr)) return false;
	LeaveButton->OnClicked.AddDynamic(this, &UMainMenu::ToLobbyMenu);


	return true;

}


void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr)
	{	
		MenuInterface->Join(GetIPAdress());		
	}
	TearDown();
}

void UMainMenu::ToCreateGameMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(CreateGameSizeBox != nullptr)) return;
	MenuSwitcher->SetActiveWidget(CreateGameSizeBox);
}

void UMainMenu::ToJoinGameMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinGameSizeBox != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinGameSizeBox);
}

void UMainMenu::ToLobbyMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(LobbySizeBox != nullptr)) return;
	MenuSwitcher->SetActiveWidget(LobbySizeBox);
}

FString UMainMenu::GetIPAdress()
{
	if (!ensure(MenuSwitcher != nullptr)) return "";
	if (!ensure(IPAdress!= nullptr)) return "";
	FString Adress = IPAdress->GetText().ToString();
	return Adress;
}

