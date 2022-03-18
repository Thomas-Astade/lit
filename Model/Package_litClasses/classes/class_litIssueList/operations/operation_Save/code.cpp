int i = 0;
myIssues.sort(SortByCreationTime);
for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
{
    (*it)->SetIndex(i++);
}

i = 0;

for (std::list<litIssue*>::iterator it = myIssues.begin(); it != myIssues.end(); it++)
{
    wxString issue;
    issue.Printf("/Issue_%d",i++);
    aConfig.SetPath(issue);
    (*it)->Save(aConfig);
}