// Copyright liusha

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraProjectEditorTarget : TargetRules
{
	public AuraProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "AuraProject" } );
	}
}
