#include "CustomAssetToolkit.h"

void FCustomAssetToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);
	InTabManager->RegisterTabSpawner(FName("OurAssetPropertyTab"), FOnSpawnTab::CreateRaw(this, &FCustomAssetToolkit::SpawnDetailTab));
	InTabManager->RegisterTabSpawner(FName("OutAssetsGraphEditorTab"), FOnSpawnTab::CreateLambda([&](const FSpawnTabArgs& SpawnTabArgs)
	{
		return SNew(SDockTab)
		[
			SNew(SGraphEditor).GraphToEdit(EdGraph)
		];
	}));
}

void FCustomAssetToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	InTabManager->UnregisterTabSpawner(FName("OurAssetPropertyTab"));
	InTabManager->UnregisterTabSpawner(FName("OutAssetsGraphEditorTab"));
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
}

void FCustomAssetToolkit::InitializeAssetEditor(const EToolkitMode::Type Mode,
                                                const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* InAssets)
{
	//create the layout
	//static const TSharedRef<FTabManager::FLayout> StandaloneOurAssetEditor =FBaseActorEditorLayout::EditorLayout();

	EdGraph = NewObject<UEdGraph>();
	EdGraph->Schema = UEdGraphSchema::StaticClass();
	EdGraph->AddToRoot();


	const  TSharedRef<FTabManager::FLayout>Layout =FTabManager::NewLayout("SimpleAssetEditorLayoutv1.0");
	Layout->AddArea(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split(
				FTabManager::NewSplitter()
						->SetSizeCoefficient(0.6f)
						->SetOrientation(Orient_Horizontal)

						->Split
					(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.8f)
					->AddTab("OutAssetsGraphEditorTab", ETabState::OpenedTab)
					)
						->Split
					(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.2f)
					->AddTab("OurAssetPropertyTab", ETabState::OpenedTab)
					)
			)
			->Split(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.4f)
					->AddTab("OutputLog", ETabState::OpenedTab)
			)
	);
	
	
	InitAssetEditor(Mode, InitToolkitHost, FName("OurAssetEditor"), Layout, true, true, InAssets);
	RegenerateMenusAndToolbars();
}

TSharedRef<SDockTab> FCustomAssetToolkit::SpawnDetailTab(const FSpawnTabArgs& SpawnTabArgs) const
{
	// Get the PropertyEditorModule to create a details view for editing properties.
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::Get().LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    
	// Create arguments for the details view.
	const FDetailsViewArgs DetailsViewArgs;
    
	// Create a Slate details view for editing properties.
	const TSharedRef<IDetailsView> AssetPropertyView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
    
	// Set the object to be edited in the details view, which automatically generates the object's property panel.
	AssetPropertyView->SetObject(GetEditingObject());
    
	// Create a new docked tab containing the details view and return it.
	return SNew(SDockTab)
	[
		AssetPropertyView
	];
}
