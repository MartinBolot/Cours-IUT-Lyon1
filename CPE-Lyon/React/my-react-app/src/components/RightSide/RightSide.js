import React, { Component } from 'react';
import Panel from "./container/Panel";

class RightSide extends Component {
  render() {
    const isPartSelected = this.props.part !== null;
    if(isPartSelected) {
      return(
        <div>
          <Panel part={this.props.part}/>
        </div>
      );
    }
    else {
      return(
        <div>No part selected</div>
      );
    }
  }
}

export default RightSide;
