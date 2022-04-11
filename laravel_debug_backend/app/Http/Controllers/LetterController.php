<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Letter;
use App\Models\History;
use App\Models\Status;

class LetterController extends Controller
{
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