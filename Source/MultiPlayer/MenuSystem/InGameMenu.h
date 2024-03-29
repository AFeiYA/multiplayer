// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();

private:
	UFUNCTION()
	void CloseInGameMenu();

	UFUNCTION()
	void BackToHobby();



private:
	//join game menu
	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;
	UPROPERTY(meta = (BindWidget))
	class UButton* LeaveButton;



	
};
