// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PerlinProcTerrain.generated.h"

class UProceduralMeshComponent;
class UMaterialInterface;

UCLASS()
class GAM415_FINAL_API APerlinProcTerrain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerlinProcTerrain();

	// makes sure x and y values cannot go below 0
	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	int XSize = 0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	int YSize = 0;

	// multiplies height of perlin noise
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ClampMin = 0))
	float ZMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	float NoiseScale = 1.0f;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	float Scale = 0;

	UPROPERTY(EditAnywhere, Meta = (ClampMin = 0))
	float UVScale = 0;

	// determines size and depth of the hole we are making
	UPROPERTY(EditAnywhere)
	float radius;

	UPROPERTY(EditAnywhere)
<<<<<<< HEAD
	float Depth;
=======
	FVector Depth;
>>>>>>> 261c68fb8c5e6a71ad121c5425e10435c5bd90d9

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Mat;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override; 

	UFUNCTION()
	void AlterMesh(FVector impactPoint);

private:
	UProceduralMeshComponent* ProcMesh;
	TArray<FVector> Vertices;
	TArray<int> Triangles;
<<<<<<< HEAD
	TArray<FVector2D> UV0;  // Changed from FVector to FVector2D
=======
	TArray<FVector> UV0;
>>>>>>> 261c68fb8c5e6a71ad121c5425e10435c5bd90d9
	TArray<FVector> Normals;
	TArray<FColor> UpVertexColors;

	int sectionID = 0;

	void CreateVertices();
	void CreateTriangles();

};
