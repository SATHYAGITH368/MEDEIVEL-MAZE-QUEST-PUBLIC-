


#include "Mover.h"

UMoverEnhanced::UMoverEnhanced()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UMoverEnhanced::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetOwner()->GetActorLocation();
}

void UMoverEnhanced::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bIsMoving) return;

    FVector CurrentLocation = GetOwner()->GetActorLocation();
    FVector TargetLocation = StartLocation + DestinationOffset;
    float MoveSpeed = DestinationOffset.Size() / Duration;

    FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
    GetOwner()->SetActorLocation(NewLocation);
}

void UMoverEnhanced::ToggleMovement(bool EnableMovement)
{
    bIsMoving = EnableMovement;
}



