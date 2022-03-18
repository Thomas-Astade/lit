//~~ void ResourceFilterMenu(wxCommandEvent& event) [litFrame] ~~
wxMenu aMenu;
std::set<wxString> tokens = milestoneListCtrl->GetResourceTokens();

aMenu.Append(ID_ClearResourceFilter ,"clear","", wxITEM_NORMAL);
aMenu.AppendSeparator();

int id = ID_AddResourceFilter;

for (std::set<wxString>::iterator it = tokens.begin(); it != tokens.end(); it++)
{
	wxString aString = *it;
	if (!aString.Trim().empty())
		aMenu.Append(id++,aString,"", wxITEM_NORMAL);
}

PopupMenu(&aMenu);