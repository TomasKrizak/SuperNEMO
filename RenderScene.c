// Return the canvas to JSROOT
gROOT->SetSpecialObject(canvas);
}
   for (int i = 0; i < 415; ++i) {
      TString name = TString::Format("polyline_%d", i);
      auto obj = (TPolyLine3D*)gFile->Get(name);
      if (obj)
         gEve->AddElement(obj);
   }

   // Optional: Also add the volume if it exists
   auto vol = gFile->Get("Wolrd Volume");
   if (vol)
      gEve->AddElement((TEveElement*)vol);
}
