// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& input) override;
	void SetupGame();
	void GameOver();
	void ProcessGuess(const FString& input);
	bool IsIsogram(const FString& input) const;
	void GetBullCows(const FString& input, int32& bullCount, int32& cowCount) const;
	
	private:
		FString hiddenWord;
		int32 livesRemaining;
		bool bGameOver;
		
		
};
