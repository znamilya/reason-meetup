open Reprocessing;

let width = 600;
let height = 600;
let stepSize = 20;

type gameState = {squarePosition: (int, int)};

let setup = env => {
  Env.size(~width, ~height, env);
  {squarePosition: (0, 0)};
};

let draw = (state, env) => {
  Draw.background(Constants.black, env);
  Draw.fill(Constants.green, env);
  Draw.rect(~pos=state.squarePosition, ~width=20, ~height=20, env);
  state;
};

let handleKey = (state, env) => {
  let (squareX, squareY) = state.squarePosition;
  let newPos =
    switch (Env.keyCode(env)) {
    | Right => ((squareX + stepSize) mod width, squareY)
    | Left => ((squareX - stepSize + width) mod width, squareY)
    | Up => (squareX, (squareY - stepSize + height) mod height)
    | Down => (squareX, (squareY + stepSize) mod height)
    | _ => state.squarePosition
    };
  {squarePosition: newPos};
};

run(~setup, ~draw, ~keyTyped=handleKey, ());