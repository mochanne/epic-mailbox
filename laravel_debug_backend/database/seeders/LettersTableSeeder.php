<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use DB;
class LettersTableSeeder extends Seeder
{
    /**
     * Run the database seeds.
     *
     * @return void
     */
    public function run()
    {
        DB::table('letters')->insert([
            'Brief_in_bus' => 0
        ]);
    }
}
