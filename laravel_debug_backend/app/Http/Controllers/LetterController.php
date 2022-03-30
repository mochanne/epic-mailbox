<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Letter;
use App\Models\History;
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

        $History->save();
        return redirect('/');
    }

    public function geenPost(){
        $History= History::create([
            'Soort_ontvangst' => 'geen post',
        ]);

        $History->save();
        return redirect('/');
    }
}