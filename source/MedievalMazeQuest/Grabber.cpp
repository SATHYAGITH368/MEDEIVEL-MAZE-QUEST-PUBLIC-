
// --------------------------------------------------------------------------------


#include "Grabber.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

UGrabber::UGrabber()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UGrabber::BeginPlay()
{
    Super::BeginPlay();
    CheckForPhysicsHandle();
}

void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (PhysicsHandle->GrabbedComponent)
    {
        PhysicsHandle->SetTargetLocation(GetPlayersReach());
    }
}

void UGrabber::Grab()
{
    FHitResult HitResult;
    bool HasHit = GetFirstPhysicsBodyInReach(HitResult);

    if (HasHit)
    {
        UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
        PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, GetPlayersReach());
    }
}

void UGrabber::Release()
{
    PhysicsHandle->ReleaseComponent();
}

void UGrabber::CheckForPhysicsHandle() const
{
    PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
    if (!PhysicsHandle)
    {
        UE_LOG(LogTemp, Error, TEXT("No Physics Handle component found on %s!"), *GetOwner()->GetName());
    }
}

bool UGrabber::GetFirstPhysicsBodyInReach(FHitResult& Hit) const
{
    // Ray-cast out to a certain distance (Reach)
    return GetWorld()->LineTraceSingleByObjectType(
        Hit,
        GetPlayersWorldPos(),
        GetPlayersReach(),
        FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
        FCollisionQueryParams(FName(TEXT("")), false, GetOwner())
    );
}

FVector UGrabber::GetPlayersWorldPos() const
{
    FVector PlayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        PlayerViewPointLocation,
        PlayerViewPointRotation
    );

    return PlayerViewPointLocation;
}

FVector UGrabber::GetPlayersReach() const
{
    FVector PlayerViewPointLocation;
    FRotator PlayerViewPointRotation;
    GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
        PlayerViewPointLocation,
        PlayerViewPointRotation
    );

    return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}
