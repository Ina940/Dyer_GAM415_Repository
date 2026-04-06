// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/BoxComponent.h"
#include "Components/SceneCaptureComponent2D.h" 
#include "GAM415_FinalCharacter.h"
#include "Components/ArrowComponent.h" 
#include "Portal.generated.h"

// lets us access player character
class GAM415_FinalCharacter;

UCLASS()
class GAM415_FINAL_API APortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneCaptureComponent2D* sceneCapture;


	UPROPERTY(EditAnywhere)
	UArrowComponent* rootArrow;

	// sets an opposite target for an opposite portal
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextureRenderTarget2D* renderTarget;

	UPROPERTY(EditAnywhere)
	UBoxComponent* boxComp;

	// allows us to set which portal are connected
	UPROPERTY(EditAnywhere)
	APortal* OtherPortal;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* mat;

	// creates overlap event to allow for teleporting
	UFUNCTION() 
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void SetBool(AGAM415_FinalCharacter* playerChar);

	UFUNCTION()
	void UpdatePortals();

}; 
