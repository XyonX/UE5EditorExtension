// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/CoreUObject/Public/UObject/Object.h"
#include "MeshAsset.generated.h"

/**
 * 
 */
UCLASS()
class EDITORPLUGIN_API UMeshAsset : public UObject
{
	GENERATED_BODY()

public:
	UMeshAsset();

	UPROPERTY(EditAnywhere)
	UStaticMesh* PreviewMesh;
};
