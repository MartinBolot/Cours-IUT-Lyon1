import { updateSelectedPart } from "../actions";
const partReducer = (state={}, action) => {
  switch (action.type) {
    case updateSelectedPart: {
      return action.obj;
    }
    default: {
      return state;
    }
  }
};

export default partReducer;
