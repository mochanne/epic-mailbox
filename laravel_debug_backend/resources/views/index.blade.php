<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Overzicht - Smart Mailbox</title>
    <link rel="stylesheet" href="css/master.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <script src="/js/main.js"></script>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@400;600&display=swap" rel="stylesheet">
    <!-- <link href="https://fonts.googleapis.com/css?family=Material+Icons|Material+Icons+Outlined|Material+Icons+Two+Tone|Material+Icons+Round|Material+Icons+Sharp" rel="stylesheet"> -->
</head>

<header>
    <img src="/img/logo.png" alt="Logo">
    <h1>Overzicht</h1>
</header>
<body>
    <p id="js--heartbeat"> {{strtotime($statusTime->updated_at)}} </p>
    <article class="content--wrapper">
        <section class="card--wrapper grid-left">
            <h1>Activiteit</h1>
            <section class="card-in--wrapper">
                <!-- <span class="material-icons-outlined" style="font-size:48px;">
                email
                </span> -->
                <img class="big_img" src="/img/mail.png" alt="">
                <p>Laatste ontvangst</p>
                <p class="fade-in bold">{{$historyLatest->ontvangen_om}}</p>
                <p class="blue bold p-padding">{{$letter->Brief_in_bus}}</p>
                <hr class="line">   
                <a href="/" class="button primary">Nu controleren</a>
                <a class="button secondary" onclick='openHistory()'>Alle post</a>
                <!-- <span class="material-icons-round grey">
                autorenew
                </span> -->
                <img class="medium_img" src="/img/renew.png" alt="">
                <p class="less-importance" id="js--time">laden...</p>
            </section>
        </section>

        <section class="card--wrapper grid-right">
            <h1>Status</h1>
            <section class="card-in--wrapper">
                <!-- <span class="material-icons-round blue" id="js--checkmark" style="font-size:48px;">
                task_alt
                </span> -->
                <img  id="js--checkmark"  class="big_img" src="/img/warning.png" alt="">
                <p>Alles werkt</p>
                <p class="status" id="status_text">naar behoren</p>
                <hr class="line" id="statusline">
                <section class="status-grid--wrapper less-importance">
                    <p id="js--connection-text">Verbinding met de brievenbus</p>
                    <!-- <p id="js--checkmark_connection" class="material-icons-round grey status-grid-right">
                    task_alt
                    </p> -->
                    <img id="js--checkmark_connection" class="medium_img center_img" src="/img/check.png" alt="">

                    <!-- Checks voor sensoren die nog toegevoegd kunnen worden -->
                    <!-- <p>Werking sensoren</p>
                    <p class="material-icons-round grey status-grid-right">
                    task_alt
                    </p> 
                    <img class="medium_img center_img" src="/img/check.png" alt=""> -->
                </section>
                <a href="/" class="button secondary">Checks uitvoeren</a>
            </section>
        </section>

        <section class="history_card_wrapper" id="js--history_card">
            <!-- <span class="material-icons-outlined blue" style="font-size:40px;" onclick='closeHistory()'>
            cancel
            </span> -->
            <img class="big_img" id="cancel" src="/img/Cancel.png" alt="" onclick='closeHistory()'>
            <h1>Geschiedenis</h1>
            <article class="letterCard--wrapper">
                <!-- Voor elke post die is ontvangen wordt er een eigen "kaartje" aangemaakt-->
                @foreach($history as $history)
                    @include('components.letterCard')
                @endforeach
            </article>
        </section>
    </article>
</body>
</html>