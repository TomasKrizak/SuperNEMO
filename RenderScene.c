void RenderScene() {
   auto canvas = dynamic_cast<TCanvas*>(object);
   if (!canvas) {
      printf("Object is not a TCanvas!\n");
      return;
   }

   // Ensure pad and view are active
   canvas->cd();
   gPad->Modified();
   gPad->Update();

   // Optionally: print all primitives
   TIter next(gPad->GetListOfPrimitives());
   TObject* obj;
   while ((obj = next())) {
      printf("Found: %s (%s)\n", obj->GetName(), obj->ClassName());

      // If it's a polyline, we can configure it
      if (obj->InheritsFrom("TPolyLine3D")) {
         auto line = (TPolyLine3D*)obj;
         line->SetLineColor(kRed); // Or whatever you like
      }
   }

   // Return the canvas to JSROOT
   gROOT->SetSpecialObject(canvas);
}
