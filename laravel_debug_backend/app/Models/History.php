<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class History extends Model
{
    use HasFactory;

    //Verwijst naar de history tabel in de mail_database.
    protected $table = "history";

    //Verwijst naar de soort_ontvangts kolom in de history tabel.
    protected $fillable = ['Soort_ontvangst'];

    //Zorgt ervoor dat Laravel niet zoekt naar een timestamp in de tabel. Voorkomt errors.
    public $timestamps = false;
}
