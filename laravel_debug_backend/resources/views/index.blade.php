<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="css/master.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@400;600&display=swap" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Material+Icons|Material+Icons+Outlined|Material+Icons+Two+Tone|Material+Icons+Round|Material+Icons+Sharp" rel="stylesheet">
</head>

<header>
    <img src="/img/logo.png" alt="Logo">
    <h1>Overzicht</h1>
</header>
<body>
    <article class="content--wrapper">
        <section class="card--wrapper grid-left">
            <h1>Activiteit</h1>
            <section class="card-in--wrapper">
                <span class="material-icons-outlined" style="font-size:48px;">
                email
                </span>
                <p>Laatste ontvangst</p>
                <p class="fade-in bold">{{$history->ontvangen_om}}</p>
                <p class="blue bold p-padding">{{$letter->Brief_in_bus}}</p>
                <hr class="line">   
                <a href="/" class="button primary">Nu controleren</a>
                <a href="/" class="button secondary">Alle post</a>
                <span class="material-icons-round grey">
                autorenew
                </span>
                <p class="less-importance" id="js--time">current_time</p>
            </section>
        </section>

        <section class="card--wrapper grid-right">
            <h1>Status</h1>
            <section class="card-in--wrapper">
                <span class="material-icons-round blue" id="#js--checkmark" style="font-size:48px;">
                task_alt
                </span>
                <p>Alles werkt naar</p>
                <p class="status">behoren</p>
                <hr class="line">
                <section class="status-grid--wrapper less-importance">
                    <p>Verbinding met de brievenbus</p>
                    <p class="material-icons-round grey status-grid-right">
                    task_alt
                    </p>
                    <p>Werking sensoren</p>
                    <p class="material-icons-round grey status-grid-right">
                    task_alt
                    </p>
                </section>
                <a href="/" class="button secondary">Checks uitvoeren</a>
            </section>
        </section>
    </article>
</body>
</html>