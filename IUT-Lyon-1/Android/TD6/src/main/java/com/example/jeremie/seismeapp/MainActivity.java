package com.example.jeremie.seismeapp;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void loadData(View view){
        AsyncTask test = new JeremieAsyncTask();
        test.execute();

    }

    public void loadURL(View view){
        String strHtml = "http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/4.5_day.geojson";
        WebView webView = (WebView) findViewById(R.id.webView);
        if (webView != null) {
            webView.loadUrl(strHtml);
        }


    }

    public void TextHTML (View view) {
        String strHtml = "<html><body><b> Ceci est un texte au format HTML </b></br>qui s’affiche très simplement</body></html>";
        WebView webView = (WebView) findViewById(R.id.webView);
        if (webView != null) {
            webView.loadData(strHtml, "text/html; charset=utf-8", "UTF-8");
        }
    }

    public void dateEtHeure(View view) {
        //Toast.makeText(this,"Hello",Toast.LENGTH_LONG).show();
        AsyncTask test = new JeremieAsyncTask();
        test.execute();

    }

    public class JeremieAsyncTask extends AsyncTask<Object, Void, String> {
        //AsyncTask est un type de fonction qui s'execute en parallèle, quand elle peut accéder au processeur (je crois)

        @Override
        protected String doInBackground(Object... urls) {


            URL url = null;
            String line="";

            //Création d'une nouvelle URL, le try/catch c'est au cas où c'est une entrée utilisateur
            try {
                url = new URL("http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/4.5_day.geojson");
            } catch (MalformedURLException e) {
                e.printStackTrace();
            }

            // On essaie de se connecter à internet
            HttpURLConnection urlConnection = null;
            try {
                assert url != null;
                urlConnection = (HttpURLConnection) url.openConnection();
            } catch (IOException e) {
                e.printStackTrace();
            }
            //Puis, on essaie de se connecter à l'URL voulu, si ça fonctionne le MémoireTampon in récupére le contenu de la page
            try {
                assert urlConnection != null;
                if (urlConnection.getResponseCode() == HttpURLConnection.HTTP_OK) {
                    BufferedReader in = new BufferedReader(
                            new InputStreamReader(urlConnection.getInputStream())
                    );

                    //On transfère le MémoireTampon en un String.
                    line = in.readLine();
                    in.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }


            return line;

        }
            @Override
            protected void onPostExecute (String result){
                //Avec que la préparation se soit fait en Background, cette fonction prend le relais
                //TextView myTime = (TextView) findViewById(R.id.Time_textView);
                //myTime.setText(result);
                WebView webView = (WebView) findViewById(R.id.webView);
                webView.loadData(result, "text/html; charset=utf-8", "UTF-8");
            }


    }
}