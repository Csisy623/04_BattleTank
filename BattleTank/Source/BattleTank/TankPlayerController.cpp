// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

//Tick
  // Super
  //AimTowardsCrosshair()

  void ATankPlayerController::Tick(float DeltaTime)
  {
     Super::Tick(DeltaTime);
     AimTowardsCrosshair();

  }

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank){
        UE_LOG(LogTemp,Warning,TEXT("not possessing AI tank"));
    }
    else
    {
        UE_LOG(LogTemp,Warning,TEXT("success possessing AI tank"));
    }
    
   
}


ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()){return;}

    //Get World Location if Linetrace through crosshair
}
