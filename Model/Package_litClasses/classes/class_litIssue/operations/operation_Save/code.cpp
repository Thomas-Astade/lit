aConfig.Write("Name",name);
aConfig.Write("Resource",resource);
aConfig.Write("Projects",projects);
aConfig.Write("Description",description);
aConfig.Write("Start",start.FormatISODate());
aConfig.Write("End",end.FormatISODate());
aConfig.Write("Created",creationTime.FormatISODate()+" "+creationTime.FormatISOTime());
aConfig.Write("State",state);
aConfig.Write("Milestone",milestone);

wxString depStr;
for (std::set<litIssue*>::iterator it = dependOn.begin(); it != dependOn.end(); it++)
{
    depStr << (*it)->index << ",";
}

aConfig.Write("Depend",depStr);

aConfig.SetPath("changes");

for (std::map<wxDateTime,wxDateTime>::iterator it = changeList.begin();
     it != changeList.end(); it++)
{
    aConfig.Write((*it).first.FormatISODate(),(*it).second.FormatISODate());
}

aConfig.SetPath("..");