#include "MeshAssetToolkit.h"

#include "EditorPlugin/Objects/MeshAsset.h"
#include "EditorPlugin/PreviewWindow/SMeshPreviewWindow.h"


void FMeshAssetToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(PreviewObjectEditorPreviewSceneTabName,FOnSpawnTab::CreateLambda([&](const FSpawnTabArgs& SpawnTabArgs)
	{
		return SNew(SDockTab)
		[
			SNew(SMeshPreviewWindow)
		];
	}));
	//Registering the details panel tab
	InTabManager->RegisterTabSpawner(PreviewObjectEditorDetailTabName,FOnSpawnTab::CreateRaw(this, &FMeshAssetToolkit::SpawnDetailTab));
	
	
}

void FMeshAssetToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	InTabManager->UnregisterTabSpawner(PreviewObjectEditorDetailTabName);
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	
}

void FMeshAssetToolkit::Init(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost,
	UObject* InAssets)
{
	const TSharedRef<FTabManager::FLayout>Layout = FTabManager::NewLayout(PreviewObjectEditorLayoutName);

	Layout->AddArea(
				FTabManager::NewPrimaryArea()
				->SetOrientation(Orient_Horizontal)
					->Split(
					
						FTabManager::NewStack()
						->AddTab(PreviewObjectEditorPreviewSceneTabName,ETabState::OpenedTab)
							)
					->Split(
						FTabManager::NewStack()
						->AddTab(PreviewObjectEditorDetailTabName,ETabState::OpenedTab)
							)
					);

	EditingPreviewObject = Cast<UMeshAsset>(InAssets);
	InitAssetEditor(Mode, InitToolkitHost, FName("PreviewObjectEditor"), Layout, true, true, InAssets);
	RegenerateMenusAndToolbars();
	
}



TSharedRef<SDockTab> FMeshAssetToolkit::SpawnDetailTab(const FSpawnTabArgs& SpawnTabArgs) const
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	const FDetailsViewArgs DetailsViewArgs;
	const TSharedRef<IDetailsView> DetailsViewWidget = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsViewWidget->SetObject(GetEditingObject());
	return SNew(SDockTab)
	[
		DetailsViewWidget
	];
	
}
