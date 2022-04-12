<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Carbon\Carbon;

class HistoryController extends Controller
{
    public function index(){
        $status = \App\Models\Status::first();
        
        //de return view('index') retouneerd het dashboard met de bijbehorende gegevens uit de database.
        return view('index',[
            'letter' => \App\Models\Letter::first(),
            'history' => \App\Models\History::all()->sortbyDesc('id')->take('10'),
            'historyLatest' => \App\Models\History::latest('id')->first(),
            'statusTime' => $status,
        ]);

    }

    //Simple pagina om te testen of de verbinding met de database werkte.
    // public function posttest(){
    //     return view('postTest',[
    //         'letter' => \App\Models\Letter::first(),
    //         'history' => \App\Models\History::all()->take('10')->sortbyDesc('id'),
    //     ]);
    // }
}
