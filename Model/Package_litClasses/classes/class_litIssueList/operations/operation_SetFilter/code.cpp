filter = 0;

if (planned)
    filter |= 1;
if (started)
    filter |= 2;
if (delayed)
    filter |= 4;
if (finished)
    filter |= 8;
if (canceled)
    filter |= 16;   

resourceFilter = GetTokens(aResourceFilter);
projectFilter = GetTokens(aProjectFilter);

BuildFilteredList();