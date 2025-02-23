// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AGrassPCGActor.generated.h"

class UPCGComponent;
class UBoxComponent;
class UNiagaraDataChannelAsset;
class UNiagaraDataChannelWriter;


UCLASS()
class ROTATIONALDYNAMICGRASS_API AAGrassPCGActor : public AActor
{
	GENERATED_BODY()

protected:
    UNiagaraDataChannelWriter* NDCWriter;
    float TimeSinceLastPrint;
	
public:	
	// Sets default values for this actor's properties
	AAGrassPCGActor();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = PCG)
    UPCGComponent* PCGComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Box)
    UBoxComponent* BaseBox;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = NiagaraGrass)
    UNiagaraDataChannelAsset* NiagaraGrassDataChannel;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = NiagaraGrass)
    FVector BaseWind;



protected:
    USceneComponent* RootSceneComponent;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    virtual void SetNDCWriter();
    virtual void WriteToNDC();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
