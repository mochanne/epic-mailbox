<?php

use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

//Deze routes zorgen ervoor dat de juiste functies worden aangeroepen. 
Route::get('/letter', '\App\Http\Controllers\LetterController@checkPost');

Route::get('/api/welpost', '\App\Http\Controllers\LetterController@welPost');
Route::get('/api/geenpost', '\App\Http\Controllers\LetterController@geenPost');
Route::get('/api/heartbeat', '\App\Http\Controllers\LetterController@status');

Route::get('/', [\App\Http\Controllers\HistoryController::class,'index']);

//Deze routes zijn gebruikt voor het testen van de front-end.
// Route::get('/posttest/', [\App\Http\Controllers\HistoryController::class,'posttest']);
// Route::get('/posttest/{amount}', [\App\Http\Controllers\HistoryController::class,'posttest']);
// Route::get('/{id}', [\App\Http\Controllers\HistoryController::class,'index']);