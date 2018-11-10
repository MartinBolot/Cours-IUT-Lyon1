import { combineReducers } from 'redux';
import robotReducer from './robotReducer';
import partReducer from './partReducer';

const globalReducer = combineReducers({
  robotReducer,
  partReducer
});

export default globalReducer;
