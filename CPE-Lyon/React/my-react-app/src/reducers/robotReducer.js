import { updateSelectedRobot } from "../actions";

const robotReducer = (state={}, action) => {
  switch (action.type) {
    case updateSelectedRobot: {
      return action.obj;
    }
    default: {
      return state;
    }
  }
};

export default robotReducer;
