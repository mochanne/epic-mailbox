<link href="https://fonts.googleapis.com/css?family=Material+Icons|Material+Icons+Outlined|Material+Icons+Two+Tone|Material+Icons+Round|Material+Icons+Sharp" rel="stylesheet">

<h1>welkom bij de test</h1>

<article class="letterCard--wrapper">
    @foreach($history as $history)
        @include('components.letterCard')
    @endforeach
</article>