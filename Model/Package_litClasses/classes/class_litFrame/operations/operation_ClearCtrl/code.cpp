switch (event.GetId())
{
	case ID_ClearResource: resourceTextCtrl->Clear();break;
	case ID_ClearProject: projectsTextCtrl->Clear();break;
	case ID_ClearResourceFilter: ResourceFilterTextCtrl->Clear();break;
	case ID_ClearProjectFilter: ProjectFilterTextCtrl->Clear();break;
};