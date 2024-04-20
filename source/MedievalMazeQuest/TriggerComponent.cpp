

#include "TriggerComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* AcceptableActor = GetAcceptableActor();
    if (AcceptableActor)
    {
        Mover->SetShouldMove(true);
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(AcceptableActor->GetRootComponent());
        if (Component)
        {
            Component->SetSimulatePhysics(false);
            AcceptableActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        }
    }
    else
    {
        Mover->SetShouldMove(false);
    }
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor*> OverlappingActors;
    GetOverlappingActors(OverlappingActors, nullptr);
    for (AActor* Actor : OverlappingActors)
    {
        if (Actor->ActorHasTag(AcceptableActorTag) && !Actor->ActorHasTag(FName("Grabbed")))
        {
            return Actor;
        }
    }
    return nullptr;
}
