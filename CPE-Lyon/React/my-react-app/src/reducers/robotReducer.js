import * as jsonSource from "../sources/robots_parts";

const robots = jsonSource.robots;
const parts = jsonSource.parts;

const robotReducer = (state={}, action) => {
  console.log(action);
  switch (action.type) {
    case "UPDATE_SELECTED_ROBOT": {
      return action.obj;
    }
    default: {
      return state;
    }
  }
};

export default robotReducer;
