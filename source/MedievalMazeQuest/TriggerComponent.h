
#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h" // Ensure you refactor the Mover component similarly
#include "TriggerComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UEnhancedTriggerComponent : public UBoxComponent
{
    GENERATED_BODY()

public:
    UEnhancedTriggerComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable)
    void AssignMover(UMoverEnhanced* NewMover);

private:
    UPROPERTY(EditAnywhere)
    FName RequiredActorTag;

    UMoverEnhanced* AssignedMover;

    // Identifies an actor that meets the requirements to trigger the mover.
    AActor* IdentifyTriggerActor() const;
};
