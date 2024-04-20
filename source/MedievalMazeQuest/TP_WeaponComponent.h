
#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "WeaponComponent.generated.h"

class ACryptRaiderCharacter;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API URefinedWeaponComponent : public USkeletalMeshComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category="Projectile")
    TSubclassOf<class ACryptRaiderProjectile> ProjectileType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Audio")
    USoundBase* FiringSound;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
    UAnimMontage* FiringAnimation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Setup")
    FVector BarrelOffset;

    URefinedWeaponComponent();

    UFUNCTION(BlueprintCallable, Category="Weapon")
    void EquipWeapon(ACryptRaiderCharacter* CharacterTarget);

    UFUNCTION(BlueprintCallable, Category="Weapon")
    void Shoot();

protected:
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    ACryptRaiderCharacter* CharacterOwner;
};
