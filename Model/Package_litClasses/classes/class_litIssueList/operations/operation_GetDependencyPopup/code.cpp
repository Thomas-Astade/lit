wxMenu* aMenu = new wxMenu;

for (unsigned int i = 0; i < myFilteredIssues.size(); i++)
{
    if (selected != i)
    {
        aMenu->Append(firstID + i,myFilteredIssues[i]->GetName(),"", wxITEM_CHECK);
        aMenu->Check(firstID + i,GetIsDependent(selected,i));
    }
}

return aMenu;