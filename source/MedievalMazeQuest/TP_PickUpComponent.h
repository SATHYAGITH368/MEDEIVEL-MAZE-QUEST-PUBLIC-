
#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "CryptRaiderCharacter.h" // Adjust based on your game's character class
#include "PickUpComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAdvancedPickUp, ACryptRaiderCharacter*, Character);

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UAdvancedPickUpComponent : public USphereComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="Interaction")
    FOnAdvancedPickUp OnAdvancedPickUp;

    UAdvancedPickUpComponent();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
