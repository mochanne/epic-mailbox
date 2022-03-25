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

// Route::get('/', function () {
//     return view('welcome');
// });

Route::get('/letter', '\App\Http\Controllers\LetterController@checkPost');
Route::get('/', [\App\Http\Controllers\HistoryController::class,'index']);
Route::get('/posttest/', [\App\Http\Controllers\HistoryController::class,'posttest']);
Route::get('/posttest/{amount}', [\App\Http\Controllers\HistoryController::class,'posttest']);
// Route::get('/{id}', [\App\Http\Controllers\HistoryController::class,'index']);