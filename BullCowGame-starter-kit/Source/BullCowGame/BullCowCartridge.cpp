// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "WordList.h"
#include "Math/UnrealMathUtility.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}
   void UBullCowCartridge::OnInput(const FString& input) // When the player hits enter
{
       ProcessGuess(input);
}

void UBullCowCartridge::SetupGame()
{
    //Welcoming the player
    PrintLine(TEXT("Welcome to Bull Cow Game!"));
    hiddenWord = words[FMath::RandRange(0,words.Num() - 1)];
    PrintLine(TEXT("The hidden word was : %s"), *hiddenWord);
    livesRemaining = 3;
    bGameOver = false; 
    PrintLine(TEXT("Please guess the %i letter word!"), hiddenWord.Len());  
}

void UBullCowCartridge::GameOver()
{
    bGameOver = true;
    PrintLine(TEXT("The hidden word was : %s"), *hiddenWord);
    PrintLine(TEXT("Press Enter to continue!"));
}

void UBullCowCartridge::ProcessGuess(const FString& input)
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        if (input == hiddenWord)
        {
            PrintLine(TEXT("Correct!"));
            GameOver();
            return;
        } 
        PrintLine(TEXT("Incorrect!"));
        if (input.Len() != hiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is %i characters long. Try Again!"), hiddenWord.Len());
        }
        if (!IsIsogram(input))
        {
            PrintLine(TEXT("No repeating letters, guess again"));
        }
        if (--livesRemaining <= 0)
        {
            PrintLine(TEXT("You've run out of lives!"));
            GameOver();
            return;
        }

        //int32 bulls, cows;
       // GetBullCows(input, bulls, cows);
       // PrintLine(TEXT("You have %i Bulls and %i Cows", bulls, cows));
        PrintLine(TEXT("Guess again, You have %i lives remaining!"), livesRemaining);
    }
}

bool UBullCowCartridge::IsIsogram(const FString& input) const
{
    for (int32 Index = 0; Index < input.Len(); Index++)
    {
        for (int32 Comparison = Index + 1; Comparison < input.Len(); Comparison++)
        {
            if (input[Index] == input[Comparison])
            {
                return false;
            }
        }
    }
    return true;
}

void UBullCowCartridge::GetBullCows(const FString& input, int32& bullCount, int32& cowCount) const
{
    bullCount = 0;
    cowCount = 0;

    //for every index of the guess is same as index of the hidden word then bullcount++
    //if not a bull was it a cow? if yes cowcount++

    for (int32 i = 0; i < input.Len(); i++)
    {
        if (input[i] == hiddenWord[i])
        {
            bullCount++;
            continue;
        }
        for (int32 j = 0; j < hiddenWord.Len(); j++)
        {
            if (input[i] == hiddenWord[j])
            {
                cowCount++;
                break;
            }
        }
    }
    
}
