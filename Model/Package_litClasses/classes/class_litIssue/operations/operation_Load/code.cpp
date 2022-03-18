//~~ void Load(wxConfigBase& aConfig) [litIssue] ~~

aConfig.Read("Name",&name,wxEmptyString);
aConfig.Read("Resource",&resource,wxEmptyString);
aConfig.Read("Projects",&projects,wxEmptyString);
aConfig.Read("Description",&description,wxEmptyString);
aConfig.Read("Milestone",&milestone);

wxString date;
aConfig.Read("Start",&date,wxEmptyString);
start.ParseDate(date.c_str());

aConfig.Read("End",&date,wxEmptyString);
end.ParseDate(date.c_str());

aConfig.Read("Created",&date,wxEmptyString);
if (!creationTime.ParseDateTime(date))
{
    creationTime = wxDateTime::Now();
    wxMilliSleep(1250);
}

aConfig.Read("State",&state,0);

aConfig.SetPath("changes");

long index;
wxString key;

for (bool found = aConfig.GetFirstEntry(key,index); found; found = aConfig.GetNextEntry(key,index))
{
    aConfig.Read(key,&date,wxEmptyString);
    wxDateTime a,b;
    a.ParseDate(key.c_str());
    b.ParseDate(date.c_str());
    changeList[a] = b;
}

SetState();

aConfig.SetPath("..");
