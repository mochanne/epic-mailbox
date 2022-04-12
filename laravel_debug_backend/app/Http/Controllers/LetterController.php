<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Letter;
use App\Models\History;
use App\Models\Status;

class LetterController extends Controller
{
    //In checkPost wordt er gekeken of er post is. Is de status in de database 0 dan wordt deze 1 en andersom.
    public function checkPost(){
        $letter = Letter::all()->first();

        if($letter->Brief_in_bus == 0){
            $letter->Brief_in_bus = 1;
        }
        else if($letter->Brief_in_bus == 1){
            $letter->Brief_in_bus = 0;
        }
        $letter->save();
        return redirect('/');
    }

    //In de welPost wordt er aangeven dat er post is en de brievenbus vol is. 
    //De meest recente tijd dat er post is gedetecteerd door de sensoren wordt getoond.
    //De WIFI module roept deze functie aan
    public function welPost(){
        $History= History::create([
            'Soort_ontvangst' => 'post',
        ]);

        $letter = letter::all()->first();

        $letter->Brief_in_bus = "Vol";

        $History->save();
        $letter->save();
        return redirect('/');
    }

    //In de geenPost wordt er aangegeven dat er geen post is en de brievenbus leeg is.
    //De laatste tijd dat er gecontroleerd is of er post is wordt getoond.
    //De WIFI module roept deze functie aan
    public function geenPost(){
        $History= History::create([
            'Soort_ontvangst' => 'geen post',
        ]);

        $letter = letter::all()->first();

        $letter->Brief_in_bus = "Leeg";

        $History->save();
        $letter->save();
        return redirect('/');
    }

    //In status wordt er gecontroleerd of de database aangeeft dat er wel of geen heartbeat heeft plaats gevonden.
    public function status(){
        $Status = Status::all()->first();

        if($Status->update == '0'){
            $Status->update = '1';
        }
        else if($Status->update == '1'){
            $Status->update = '0';
        }

        $Status->save();
        return redirect('/');
    }
}