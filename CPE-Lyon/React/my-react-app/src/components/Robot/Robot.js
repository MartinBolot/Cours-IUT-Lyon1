import React, { Component } from 'react';
import Label from "./container/Label";
import Visual from "./container/Visual";

class Robot extends Component {
  constructor(props) {
    super(props);
    console.log(this.props.robot);
    this.state = {
      id: this.props.robot.id,
      label: this.props.robot.label,
    };
  }
  render() {
    return (
      <div>
        <Label label={this.state.label}/>
        <Visual/>
      </div>

    );
  }
}

export default Robot;
