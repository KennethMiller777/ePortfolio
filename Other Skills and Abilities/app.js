/*
GAME RULES:
- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game
*/

var playerScores, roundScore, activePlayer, gamePlaying, winningScore;
init();

// roll dice button event handler
document.querySelector('.btn-roll').addEventListener('click', function() {
    if (gamePlaying) {
        var dice1 = Math.floor((Math.random() * 6) + 1);
        var dice2 = Math.floor((Math.random() * 6) + 1);
        var diceDOM1 = document.querySelector('.dice1');
        var diceDOM2 = document.querySelector('.dice2');
    
        diceDOM1.style.display = 'block';
        diceDOM1.src = 'dice-' + dice1 + '.png';
        
        diceDOM2.style.display = 'block';
        diceDOM2.src = 'dice-' + dice2 + '.png';
        
        if (dice1 === 6 && dice2 === 6) {
            dice1 = 0;
            dice2 = 0;
            playerScores[activePlayer] = 0;
            document.querySelector('#score-' + activePlayer).textContent = playerScores[activePlayer];
            nextPlayer();
        }
            
        if (dice1 !== 1 && dice2 !== 1) {
            roundScore += dice1 +dice2;
            document.querySelector('#current-' + activePlayer).textContent = roundScore; 
        }
        else {
            nextPlayer();
        } 
    }
});

// hold points event handler
document.querySelector('.btn-hold').addEventListener('click', function() {
    if (gamePlaying) {
 
        //add current score to global score
        playerScores[activePlayer] += roundScore;
    
        //update UI
        document.querySelector('#score-' + activePlayer).textContent = playerScores[activePlayer];
        
        var input = document.querySelector('.final-score').value;
        
        if(input)
            winningScore = input;
        else
            winningScore = 100;
        
        //Check if player won
        if (playerScores[activePlayer] >= winningScore) {
            document.querySelector('#name-' + activePlayer).textContent = 'Winner!'
            document.querySelector('.dice1').style.display = 'none';
            document.querySelector('.dice2').style.display = 'none';
            document.querySelector('.player-' + activePlayer + '-panel').classList.remove('active');
            document.querySelector('.player-' + activePlayer + '-panel').classList.add('winner');
            gamePlaying = false;
        }
        else 
            nextPlayer();
    }
});

// new game event handler
document.querySelector('.btn-new').addEventListener('click', init);

// DRY function
function nextPlayer() {
    var diceDOM1 = document.querySelector('.dice1');
    diceDOM1.style.display = 'block';
    var diceDOM2 = document.querySelector('.dice2');
    diceDOM2.style.display = 'block';
    roundScore = 0;
    document.querySelector('#current-' + activePlayer).textContent = roundScore;
    activePlayer === 0 ? activePlayer = 1 : activePlayer = 0;
    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('.player-1-panel').classList.toggle('active');
    diceDOM1.style.display = 'none';
    diceDOM2.style.display = 'none';
};

//initialization function
function init() {
    winningScore = 0;
    gamePlaying = true;
    playerScores = [0, 0];
    roundScore = 0;d
    activePlayer = Math.floor(Math.random() * 2);
    
    //sets all classes to default
    document.querySelector('.player-0-panel').classList.remove('winner');
    document.querySelector('.player-1-panel').classList.remove('winner');
    document.querySelector('.player-0-panel').classList.remove('active');
    document.querySelector('.player-1-panel').classList.remove('active');
    document.querySelector('.player-0-panel').classList.add('active');
    
    // hides the dice at the beginning of the game
    document.querySelector('.dice1').style.display = 'none'; 
    document.querySelector('.dice2').style.display = 'none';
    
    //sets all displays to 0 before game starts
    document.getElementById('score-0').textContent = '0';
    document.getElementById('score-1').textContent = '0';
    document.getElementById('current-0').textContent = '0';
    document.getElementById('current-1').textContent = '0';
    document.querySelector('#name-0').textContent = 'Player 1';
    document.querySelector('#name-1').textContent = 'Player 2';
    
    //checks to see who will start the game off. 
    //if player 2 starts the game, toggle display for correction, else nothing
    if (activePlayer !== 0) { 
        document.querySelector('.player-0-panel').classList.toggle('active');
        document.querySelector('.player-1-panel').classList.toggle('active');
    }
};