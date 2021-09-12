// Store 1 in a constant variable, so we can use the constant variable later
// rather than having to write 1 in our program. This will make our code a
// lot more readable.
const HOME_TEAM_WON = 1;

function tournamentWinner(competitions, results) {
  const scores = new Map();

  for (let idx = 0; idx < competitions.length; idx++) {
    const [homeTeam, awayTeam] = competitions[idx];
    const result = results[idx];
    const winningTeam = result === HOME_TEAM_WON ? homeTeam : awayTeam;
    const currentScore = scores.get(winningTeam) || 0;
    scores.set(winningTeam, currentScore + 3);
  }

  let currentBestScore = 0;
  let currentBestTeam = '';
  scores.forEach((score, team) => {
    if (score > currentBestScore) {
      currentBestScore = score;
      currentBestTeam = team;
    }
  });

  return currentBestTeam;
}

