wxInitAllImageHandlers();
myFrame = new litFrame;
myFrame->Init();
SetTopWindow(myFrame);
myFrame->Show(true);

if (argc > 1)
	myFrame->Load(argv[1]);

return true;