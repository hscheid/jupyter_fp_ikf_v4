// c++ Klassen
#include <iostream>
// Einbinden der notwendigen root Klassen
#include "TGraphErrors.h"
#include "TF1.h"

int analysis_v3()
{
  // die x und y Werte der Messung werden in arrays gespeichert:
  double xValues[] = {50.,60.,70.,72.,74.,76.,78.,80.,90.,100.};
  double yValues[] = {7000,7000,7000,7300,9540, 12320, 13600, 14000,14000,14000};
  // Arrays haben keine funktionalität um ihr laenge abfragen zu können. Hier ein trick um die anzahl der
  // Elemente in einem Array zu bestimmen;
  int sizeX = sizeof(xValues)/sizeof(xValues[0]);
  int sizeY = sizeof(xValues)/sizeof(yValues[0]);
  if(sizeY != sizeX)
  {
    std::cout << "Not the same number of X and Y entries. Abort!" << '\n';
    return 0;
  }
  // die fehler der X und Y werte:
  double uncertaintyX = 2.5;
  double uncertaintyY = 0.;
  // um die fehler in X und Y zu speichern brauchen wir arrays mit der gleichen anzahl einträge wie zufor
  double xError[sizeX];
  double yError[sizeY];
  // die fehler auf der X und Y Achse können wir in einem loop in arrays schreiben
  for (int i = 0; i < sizeX; i++) {
    xError[i] = uncertaintyX;
    yError[i] = uncertaintyY;
  }

  // Jetzt können wir einen TGraphErrors anlegen
  TGraphErrors *gr = new TGraphErrors(sizeX,xValues,yValues,xError,yError);
  // Das ganze jetzt noch ansehnlich machen:
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1.2);
  gr->SetMarkerColor(kBlue+1);

  // Jetzt brauchen wir noch unsere funktion
  // in [] stehen die "freien" parameter der funktion die bei einem fit verändert werden können um die daten am besten zu beschreiben
  TF1* func = new TF1("func","[0] - ([0]/ ( exp((x-[1]) /[2] ) +2 ) )",50 ,100);
  // Es ist sinnvoll die freien parameter auf realistische startwerte für die optimierung zu setzen.
  func->SetParameter(0,14000);
  func->SetParameter(1,75);
  func->SetParameter(2,3);
  // Der Fit des Graphs gr mit der Funktion func in ihrer range
  gr->Fit(func,"R");

  // wir malen den graph nun. Hierbei sind folgende optionen relevant:
  // A: Die Achsen des Graphen werden gemalt
  // P: Die Punkte werden gemalt
  // E: Die Fehler werden gemalt
  gr->Draw("APE");
  func->Draw("same");
  return 1;
}
