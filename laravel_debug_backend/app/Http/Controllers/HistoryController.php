<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HistoryController extends Controller
{
    public function index(){

        return view('index',[
            'letter' => \App\Models\Letter::first(),
            'history' => \App\Models\History::latest('id')->first(),
        ]);
    }
}
