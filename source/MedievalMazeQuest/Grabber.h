

// ------------------------------------------------------------------------------------------------------------------------------


#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class YOURGAME_API UGrabber : public USceneComponent
{
    GENERATED_BODY()

public:
    UGrabber();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable)
    void Grab();

    UFUNCTION(BlueprintCallable)
    void Release();

private:
    float Reach = 100.f;

    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    void CheckForPhysicsHandle() const;
    bool GetFirstPhysicsBodyInReach(FHitResult& Hit) const;
    FVector GetPlayersReach() const;
    FVector GetPlayersWorldPos() const;
};
