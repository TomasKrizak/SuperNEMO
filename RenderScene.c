void RenderScene()
{
   // 'object' is the top-level object passed from JSROOT (e.g. 3DPlot)
   auto list = dynamic_cast<TEveElement*>(object);
   if (!list) {
      //printf("Object is not a TEveElement\n");
      return;
   }

   list->SetRnrSelf(kTRUE);
   list->SetRnrChildren(kTRUE);

   // Go over all children and activate them
   TIter next(list->GetListChildren());
   TObject* obj;
   while ((obj = next())) {
      auto eve = dynamic_cast<TEveElement*>(obj);
      if (eve) {
         eve->SetRnrSelf(kTRUE);
         eve->SetRnrChildren(kTRUE);
         // Optional: Set color or style here
      }
   }

   // Return list to JSROOT
   gROOT->SetSpecialObject(list);
}

