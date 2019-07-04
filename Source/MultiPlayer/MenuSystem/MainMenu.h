// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
//#include "MenuInterface.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"


/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

private:

//lobby menu
	UPROPERTY(meta = (BindWidget))
	class UWidget* LobbySizeBox;
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* FindButton;



//create game menu
	UPROPERTY(meta = (BindWidget))
	class UWidget* CreateGameSizeBox;
	UPROPERTY(meta = (BindWidget))
	class UButton* CreateButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

//join game menu
	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinGameSizeBox;
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* LeaveButton;
	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAdress;
	
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();

	UFUNCTION()
	void ToCreateGameMenu();

	UFUNCTION()
	void ToJoinGameMenu();

	UFUNCTION()
	void ToLobbyMenu();

	UFUNCTION()
	FString GetIPAdress();




};
