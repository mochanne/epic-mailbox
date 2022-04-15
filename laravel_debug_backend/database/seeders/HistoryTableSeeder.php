<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use DB;

class HistoryTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('history')->insert([
            'Soort_ontvangst' => "brief"
        ]);
    }
}
