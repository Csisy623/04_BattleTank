// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    //auto ControlledTank = GetControlledTank();
    auto PlayerTank = GetPlayerTank();

    if(!PlayerTank){
        UE_LOG(LogTemp,Warning,TEXT("not find player tank"));
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("success find player a tank"));
    }


    
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if(GetPlayerTank())
    {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    }
    
    
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

    if(!PlayerPawn){
        return nullptr;    //Note The !, very important
    }

    return Cast<ATank>(PlayerPawn);
}
