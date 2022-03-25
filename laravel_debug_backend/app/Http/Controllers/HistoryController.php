<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Carbon\Carbon;

class HistoryController extends Controller
{
    public function index(){

        return view('index',[
            'letter' => \App\Models\Letter::first(),
            'history' => \App\Models\History::all()->sortbyDesc('id')->take('10'),
            'historyLatest' => \App\Models\History::latest('id')->first(),
        ]);

    }

    public function posttest(){
        return view('postTest',[
            'letter' => \App\Models\Letter::first(),
            'history' => \App\Models\History::all()->take('10')->sortbyDesc('id'),
        ]);
    }
}
