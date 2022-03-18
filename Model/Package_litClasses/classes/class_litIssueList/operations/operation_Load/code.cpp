New();
int i = 0;
do
{
    wxString issue;
    issue.Printf("/Issue_%d",i++);
    if (!aConfig.HasGroup(issue))
        break;
        
    aConfig.SetPath(issue);
    litIssue* newIssue = new litIssue("new");
    myIssues.push_back(newIssue);
    newIssue->Load(aConfig);
} while (true);

i = 0;
for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
    (*it)->SetIndex(i++);

i = 0;
for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
{
    wxString issue;
    issue.Printf("/Issue_%d",i++);
    aConfig.SetPath(issue);
    LoadDepend(aConfig, (*it));
}

BuildFilteredList();